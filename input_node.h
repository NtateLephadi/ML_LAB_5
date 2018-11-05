#include <vector>
#include <iostream>
#include <math.h>

#ifndef INPUT_NODE_H
#define INPUT_NODE_H

class input_node{

private:
	std::vector<double>
		inputs,
		bias,
		hidden_layer_outputs,
		hidden_layer_weights;
	std::vector<std::vector<double>> weights;
	double output_layer_bias, target;
public:
	input_node();
	~input_node();
	void set_inputs(std::vector<double>);
	void set_target(double);
	void set_hidden_layer_weights(std::vector<double>);
	void set_bias(std::vector<double>);
	void set_weights(std::vector<std::vector<double>>);
	void to_string();
	void set_output_layer_bias(double);
	double product_sum(int);
	double hidden_product_sum();
	double sigmoid(double);
	double mean_squared_error();
};
#endif
