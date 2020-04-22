export GCOV_PREFIX=`pwd`/build/CMakeFiles/main_test.dir/tests/
export GCOV_PREFIX_STRIP=`echo $GCOV_PREFIX | grep -o '/'  | wc -l`
curr=`pwd`
echo $GCOV_PREFIX
echo $GCOV_PREFIX
echo $GCOV_PREFIX
echo $GCOV_PREFIX
echo $GCOV_PREFIX
echo $GCOV_PREFIX
echo $GCOV_PREFIX

cd build; make test;cd $curr 
cd $GCOV_PREFIX; gcov *.cpp.gcda
lcov -t "result" -o ex_test.info -c -d .
genhtml -o res $GCOV_PREFIX\ex_test.info
cp -r . $curr/reports/