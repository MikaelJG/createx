echo "Compiling.."
sleep 1
g++ -Wall -Werror -Wextra -pedantic -std=c++17 ./createx.cpp

sleep 1
echo "Compiled."
echo "Launching first test."
sleep 1
./a.out txt est_dir

# echo "Launching second test."
# sleep 1 
# 
# ./a.out xx un_dir
# 
# echo "Launching third test."
# sleep 1 
# 
# ./a.out ud vsd re 
# 
# echo "Launching fourth test."
# sleep 1 
# 
# ./a.out wer 
# 
# echo "Launching fourth test."
# sleep 1 
# 
# ./a.out rb ref_dir 
