#include <iostream>

// auto sum() {
//     return 0;
// }
// template <typename first_type, typename... var_type>
// auto sum(first_type first_var, var_type... args){
//     return first_var + sum(args...);
// }

// template <typename first_type, typename... var_type>
// auto average(first_type first_var, var_type... args) {
//     auto sum_var = first_var + sum(args...);
//     return sum_var / (sizeof...(args) + 1); 
// }
template<typename ... T>
auto average(T ... t) {
  return (t + ... ) / sizeof...(t);
}
int main(int argc, char*argv[]) {
    std::cout << average(1) << std::endl;
}
