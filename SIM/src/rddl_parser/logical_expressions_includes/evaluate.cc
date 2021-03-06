void LogicalExpression::evaluate(double& /*res*/, State const& /*current*/,
                                 ActionState const& /*actions*/) const {
    assert(false);
}

/*****************************************************************
                           Atomics
*****************************************************************/

void StateFluent::evaluate(double& res, State const& current,
                           ActionState const& /*actions*/) const {
    res = current[index];
}

void ActionFluent::evaluate(double& res, State const& /*current*/,
                            ActionState const& actions) const {
    res = actions[index];
}

void NumericConstant::evaluate(double& res, State const& /*current*/,
                               ActionState const& /*actions*/) const {
    res = value;
}

/*****************************************************************
                           Connectives
*****************************************************************/

void Conjunction::evaluate(double& res, State const& current,
                           ActionState const& actions) const {
    for (unsigned int i = 0; i < exprs.size(); ++i) {
        exprs[i]->evaluate(res, current, actions);

        if (MathUtils::doubleIsEqual(res, 0.0)) {
            return;
        } else {
            assert(MathUtils::doubleIsEqual(res, 1.0));
        }
    }
    res = 1.0; // The empty conjunction is true
}

void Disjunction::evaluate(double& res, State const& current,
                           ActionState const& actions) const {
    for (unsigned int i = 0; i < exprs.size(); ++i) {
        exprs[i]->evaluate(res, current, actions);

        if (MathUtils::doubleIsEqual(res, 1.0)) {
            return;
        } else {
            assert(MathUtils::doubleIsEqual(res, 0.0));
        }
    }
    res = 0.0; // The empty disjunction is false
}

void EqualsExpression::evaluate(double& res, State const& current,
                                ActionState const& actions) const {
    assert(exprs.size() == 2);

    double lhs = 0.0;
    exprs[0]->evaluate(lhs, current, actions);

    double rhs = 0.0;
    exprs[1]->evaluate(rhs, current, actions);

    res = MathUtils::doubleIsEqual(lhs, rhs);
}

void GreaterExpression::evaluate(double& res, State const& current,
                                 ActionState const& actions) const {
    assert(exprs.size() == 2);

    double lhs = 0.0;
    exprs[0]->evaluate(lhs, current, actions);

    double rhs = 0.0;
    exprs[1]->evaluate(rhs, current, actions);

    res = MathUtils::doubleIsGreater(lhs, rhs);
}

void LowerExpression::evaluate(double& res, State const& current,
                               ActionState const& actions) const {
    assert(exprs.size() == 2);

    double lhs = 0.0;
    exprs[0]->evaluate(lhs, current, actions);

    double rhs = 0.0;
    exprs[1]->evaluate(rhs, current, actions);

    res = MathUtils::doubleIsSmaller(lhs, rhs);
}

void GreaterEqualsExpression::evaluate(double& res, State const& current,
                                       ActionState const& actions) const {
    assert(exprs.size() == 2);

    double lhs = 0.0;
    exprs[0]->evaluate(lhs, current, actions);

    double rhs = 0.0;
    exprs[1]->evaluate(rhs, current, actions);

    res = MathUtils::doubleIsGreaterOrEqual(lhs, rhs);
}

void LowerEqualsExpression::evaluate(double& res, State const& current,
                                     ActionState const& actions) const {
    assert(exprs.size() == 2);

    double lhs = 0.0;
    exprs[0]->evaluate(lhs, current, actions);

    double rhs = 0.0;
    exprs[1]->evaluate(rhs, current, actions);

    res = MathUtils::doubleIsSmallerOrEqual(lhs, rhs);
}

void Addition::evaluate(double& res, State const& current,
                        ActionState const& actions) const {
    res = 0.0;
    for (unsigned int i = 0; i < exprs.size(); ++i) {
        double exprRes = 0.0;
        exprs[i]->evaluate(exprRes, current, actions);
        res += exprRes;
    }
}

void Subtraction::evaluate(double& res, State const& current,
                           ActionState const& actions) const {
    exprs[0]->evaluate(res, current, actions);

    for (unsigned int i = 1; i < exprs.size(); ++i) {
        double exprRes = 0.0;
        exprs[i]->evaluate(exprRes, current, actions);
        res -= exprRes;
    }
}

void Multiplication::evaluate(double& res, State const& current,
                              ActionState const& actions) const {
    res = 1.0;
    for (unsigned int i = 0; i < exprs.size(); ++i) {
        double exprRes = 0.0;
        exprs[i]->evaluate(exprRes, current, actions);
        res *= exprRes;

        if (MathUtils::doubleIsEqual(res, 0.0)) {
            return;
        }
    }
}

void Division::evaluate(double& res, State const& current,
                        ActionState const& actions) const {
    exprs[0]->evaluate(res, current, actions);

    for (unsigned int i = 1; i < exprs.size(); ++i) {
        if (MathUtils::doubleIsEqual(res, 0.0)) {
            return;
        }

        double exprRes = 0.0;
        exprs[i]->evaluate(exprRes, current, actions);
        assert(!MathUtils::doubleIsEqual(exprRes, 0.0));
        res /= exprRes;
    }
}

/*****************************************************************
                          Unaries
*****************************************************************/

void Negation::evaluate(double& res, State const& current,
                        ActionState const& actions) const {
    expr->evaluate(res, current, actions);

    res = MathUtils::doubleIsEqual(res, 0.0);
}

void ExponentialFunction::evaluate(double& res, State const& current,
                                   ActionState const& actions) const {
    expr->evaluate(res, current, actions);

    res = std::exp(res);
}

/*****************************************************************
                   Probability Distributions
*****************************************************************/

// Since evaluate is used only for (deterministic) SACs (which cannot contain a
// probability distribution) and to generate the training set (where we want to
// sample successors), these functions sample an outcome.
void BernoulliDistribution::evaluate(double& res, State const& current,
                                     ActionState const& actions) const {
    expr->evaluate(res, current, actions);
    double randNum = MathUtils::generateRandomNumber();

    res = MathUtils::doubleIsSmaller(randNum, res);
}

void DiscreteDistribution::evaluate(double& res, State const& current,
                                    ActionState const& actions) const {
    double randNum = MathUtils::generateRandomNumber();
    double probSum = 0.0;
    for (unsigned int i = 0; i < probabilities.size(); ++i) {
        res = 0.0;
        probabilities[i]->evaluate(res, current, actions);
        probSum += res;
        if (MathUtils::doubleIsSmaller(randNum, probSum)) {
            res = 0.0;
            values[i]->evaluate(res, current, actions);
            return;
        }
    }
    assert(false);
}

/*****************************************************************
                         Conditionals
*****************************************************************/

void IfThenElseExpression::evaluate(double& res, State const& current,
                                    ActionState const& actions) const {
    condition->evaluate(res, current, actions);

    if (MathUtils::doubleIsEqual(res, 0.0)) {
        valueIfFalse->evaluate(res, current, actions);
    } else {
        valueIfTrue->evaluate(res, current, actions);
    }
}

void MultiConditionChecker::evaluate(double& res, State const& current,
                                     ActionState const& actions) const {
    for (unsigned int index = 0; index < conditions.size(); ++index) {
        conditions[index]->evaluate(res, current, actions);

        if (!MathUtils::doubleIsEqual(res, 0.0)) {
            effects[index]->evaluate(res, current, actions);
            return;
        }
    }
    assert(false);
}
