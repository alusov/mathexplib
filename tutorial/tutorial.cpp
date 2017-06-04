/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testinterval.cpp
 * Author: Alexander Usov
 *
 * Created on January 20, 2017, 9:13 AM
 */
#include <iostream>
#include "funcs/testfuncs.hpp" //test functions
#include "expression/expr.hpp"//library of math expressions
#include "expression/algorithm.hpp"//algorithms

using namespace expression;
using namespace interval;


void calcFunc(const std::string& name, Expr<double> expr, const std::vector<double>& vars)
{
	auto result = expr.calc(vars, FuncAlg<double>());//FuncAlg<double>() - algorithm to calculate value of a function	
	std::cout << name << " = " << result << '\n';
}

void calcInterval(const std::string& name, Expr<Interval<double>> expr, const std::vector<Interval<double>>& vars)
{
	auto result = expr.calc(vars, InterEvalAlg<double>());//InterEvalAlg<double>() - algorithm to estimate value a function on the box
	std::cout << name << " = " << result;
}

int main(int argc, char** argv) {
	
	std::cout << "\n****************Tutorial************************\n";	
        
	//get Ackley1 expression to calculate value at a point. 
        auto expr = Ackley1<double>(2);	
	//calculate value at the point (0.0, 0.0)
	calcFunc("Ackley1(0.0, 0.0)", expr, { 0.0, 0.0});
	//calculate value at the point (1.0, 1.0)
	calcFunc("Ackley1(1.0, 1.0)", expr, { 1.0, 1.0 });
        //calculate value at the point (2.0, 2.0)
	calcFunc("Ackley1(2.0, 2.0)", expr, { 2.0, 2.0 });
	//get Ackley1 expression to estimate the function on a box.
	auto exprInterval = Ackley1<Interval<double>>(2);
        //estimate the function on the box (( 0.5, 1.5 ), ( -0.5, 0.5 ))
	calcInterval("Ackley1((0.5, 1.5),(-0.5, 0.5 ))", exprInterval, { { 0.5, 1.5 }, { -0.5, 0.5 } });
        //estimate the function on the box (( 0.9, 1.1 ), ( -0.1, 0.1 ))
	calcInterval("Ackley1((0.9, 1.1),(-0.1, 0.1 ))", exprInterval, { { 0.9, 1.1 }, { -0.1, 0.1 } });

    	return 0;
}
