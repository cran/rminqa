#include "../inst/include/optim.h"
using namespace Rcpp;

// New interface for v0.3.1 the old one still works below as well (from optim.h header)
// This version allows interfacing directly with functions or functions within classes with
// little overhead, without requiring a new class definition

double fn(const std::vector<double> &x){
  double x1 = x[0];
  double x2 = x[1];
  return 100 * std::pow((x2 - x1 * x1), 2) + std::pow(1 - x1, 2);
};

// or equivalently as a function witin another class
struct func {
  double fn(const std::vector<double> &x){
    double x1 = x[0];
    double x2 = x[1];
    return 100 * std::pow((x2 - x1 * x1), 2) + std::pow(1 - x1, 2);
  };
};

//' @title Example 0a: Minimize Rosenbrock function using bobyqa
//' @description Minimize Rosenbrock function using bobyqa and
//'             expect a normal exit from bobyqa.
//' @return No return value, called for side effects.
//' @examples
//' fr <- function(x) {   ## Rosenbrock Banana function
//'  x1 <- x[1]
//'  x2 <- x[2]
//'  100 * (x2 - x1 * x1)^2 + (1 - x1)^2
//' }
//' (x1 <- minqa::bobyqa(c(1, 2), fr, lower = c(0, 0), upper = c(4, 4)))
//' ## => optimum at c(1, 1) with fval = 0
//' str(x1) # see that the error code and msg are returned
//'
//' ## corresponding C++ implementation:
//' bobyqa_rosen_test1()
//' @useDynLib rminqa, .registration = TRUE
//' @export
// [[Rcpp::export]]
void bobyqa_rosen_test1() {
 std::vector<double> x{1.0, 2.0};
 auto op = bobyqad(x);
 op.fn<&fn>();
 // add bounds
 op.set_bounds({0.0,0.0},{4.0,4.0});
 op.minimise();
 x = op.values();
 
 Rcpp::Rcout << "-------------------------" << std::endl;
 Rcpp::Rcout << "par = ";
 for(auto xi: x)Rcpp::Rcout << xi << " ";
 Rcpp::Rcout << "\n" << std::endl;
 Rcpp::Rcout << "fval = " << op(x) << std::endl;
 Rcpp::Rcout << "-------------------------" << std::endl;
}

//'@title Example 0b: Minimize Rosenbrock function using bobyqa
//'@description Minimize Rosenbrock function using bobyqa and
//'             expect a normal exit from bobyqa. Allows for user input.
//'@param start Starting values of the algorithm.
//'@param lower Lower bounds of the parameters.
//'@param upper Upper bounds of the parameters.     
//'@return No return value, called for side effects.
//'@examples
//'fr <- function(x) {   ## Rosenbrock Banana function
//'  x1 <- x[1]
//'  x2 <- x[2]
//'  100 * (x2 - x1 * x1)^2 + (1 - x1)^2
//'}
//'(x1 <- minqa::bobyqa(c(1, 2), fr, lower = c(0, 0), upper = c(4, 4)))
//'## => optimum at c(1, 1) with fval = 0
//'str(x1) # see that the error code and msg are returned
//'
//'## corresponding C++ implementation:
//'bobyqa_rosen_test2(c(1,2),c(0,0),c(4,4))
//' @importFrom Rcpp evalCpp
//' @export
// [[Rcpp::export]]
void bobyqa_rosen_test2(SEXP start, SEXP lower, SEXP upper) {
 // demonstrate user input and interface with class function
 std::vector<double> start_ = Rcpp::as<std::vector<double>>(start);
 std::vector<double> lower_ = Rcpp::as<std::vector<double>>(lower);
 std::vector<double> upper_ = Rcpp::as<std::vector<double>>(upper);
 auto f1 = func{};
 auto op = bobyqad(start_);
 op.fn<&func::fn,func>(&f1);
 // add bounds
 op.set_bounds(lower_, upper_);
 op.minimise();
 std::vector<double> x = op.values();
 
 Rcpp::Rcout << "-------------------------" << std::endl;
 Rcpp::Rcout << "par = ";
 for(auto xi: x)Rcpp::Rcout << xi << " ";
 Rcpp::Rcout << "\n" << std::endl;
 Rcpp::Rcout << "fval = " << op(x) << std::endl;
 Rcpp::Rcout << "-------------------------" << std::endl;
}
