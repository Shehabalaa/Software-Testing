curr=`pwd`

cd build;
cmake -DCMAKE_EXPORT_COcMPILE_COMMANDS=ON ..
make; 
make test;
cd $curr 
cd `pwd`/build/; 




for file in `ls test_*`; do
    echo $file >> ../reports/mutation/mutation.txt
    mull-cxx --report-name report.txt  -test-framework CustomTest ./$file\
    -ld-search-path=/home/shehab/libs/boost/boost_test/lib/ -ld-search-path=/usr/lib/x86_64-linux-gnu/\
    -ld-search-path=/lib/x86_64-linux-gnu/\
    -ld-search-path=/lib/x86_64-linux-gnu/\
    -compilation-flags="-DBOOST_TEST_DYN_LINK -DHANDMADE_MATH_CPP_MODE -DHANDMADE_MATH_IMPLEMENTATION -I/home/shehab/libs/boost/boost_test/include -I/home/shehab/Desktop/Software-Testing/."\
    | grep -e "Mutation score\|HMM.h" >> ../reports/mutation/mutation.txt
    echo "--------------" >> ../reports/mutation/mutation.txt
    echo $file\done
done