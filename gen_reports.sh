export GCOV_PREFIX='./'
# export GCOV_PREFIX_STRIP=`echo $GCOV_PREFIX | grep -o '/'  | wc -l`
curr=`pwd`

cd build; make test;cd $curr 
cd `pwd`/build/CMakeFiles/; gcov -b -c ./*.dir/tests/*.cpp.gcda
lcov -d . -c --rc lcov_branch_coverage=1  -o ex_test.info -t reports
genhtml --branch-coverage --highlight --legend  -o res $GCOV_PREFIX\ex_test.info
cp -r . $curr/reports/