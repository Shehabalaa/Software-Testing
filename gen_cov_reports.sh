# export GCOV_PREFIX='./'
# export GCOV_PREFIX_STRIP=`echo $GCOV_PREFIX | grep -o '/'  | wc -l`
curr=`pwd`

cd build;
cmake ..; 
make; 
make test;
cd $curr 

cd `pwd`/build/CMakeFiles/; 
gcov -b -c `find ./*.dir/tests/ | grep .cpp.gcda`
lcov -d . -c --rc lcov_branch_coverage=1  -o ex_test.info -t reports
genhtml --branch-coverage --highlight --legend  -o res $GCOV_PREFIX\ex_test.info
cp -r ./res/ $curr/reports/