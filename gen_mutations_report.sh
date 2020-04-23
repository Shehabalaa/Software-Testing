curr=`pwd`

cd build;
cmake ..; 
make; 
make test;
cd $curr 
cd `pwd`/build/; 


for file in `ls test_*`; do
    echo $file >> ../reports/mutation/mutation.txt
    mull-cxx -test-framework CustomTest ./$file --ld-search-path $boost_test/lib/ | grep HMM.h >> ../reports/mutation/mutation.txt
    echo "------" >> ../reports/mutation/mutation.txt
    echo "------" >> ../reports/mutation/mutation.txt
done