Installation Guidelines

Step-1:
Compile the rddl-parser executable

cd src/rddl_parser
make


Step-2:
Compile the prost executable

cd src/search
make


Step-3:
Create a dynamic library clibxx.so

cd src/search/.obj
g++ -shared -o clibxx.so -fPIC *.o ./utils/*.o


Step-4:
Copy the following two files to the OpenAI project

cp src/rddl_parser/rddl-parser.exe  <base-dir>/Open-AI/rddl/lib
cp src/search/.obj/clibxx.so  <base-dir>/Open-AI/rddl/lib


Please note that you should substitute the base-dir with the path to the Open AI project base folder
