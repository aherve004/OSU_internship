Installation Guidelines

Step-1
Remember to copy the following files from SIM

src/rddl_parser/rddl-parser.exe
src/search/.obj/clibxx.so

to rddl/lib


Step-2
Set the domain and problem instance in gym/envs/__init__.py at the very end of the file.
Please search for "RDDL-v1" to get there.



Step-3
Just run the python file RDDL.py in gym/envs/rddl as

python gym/envs/rddl/RDDL.py
