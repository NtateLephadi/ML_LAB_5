#include "input_node.h"

input_node::input_node(){}

input_node::~input_node(){}

void input_node::set_inputs(std::vector<double> v){
	this->inputs = v;
}

void input_node::set_bias(std::vector<double> v){
	this->bias = v;
}

void input_node::set_hidden_layer_weights(std::vector<double> v){
	this->hidden_layer_weights = v;
}

void input_node::set_weights(std::vector<std::vector<double>> v){
	this->weights = v;
}

void input_node::set_output_layer_bias(double d){
	this->output_layer_bias = d;
}

void input_node::to_string(){
	std::cout << "inputs" << std::endl;
	for(size_t i; i < this->inputs.size(); i++){
		std::cout << this->inputs[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "weights" << std::endl;
	for(size_t i=0; i < this->weights.size(); i++){
		for(size_t j=0; j < this->weights[i].size(); j++){
			std::cout << this->weights[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << "product sum" << '\n';
	for (size_t j = 0; j < 2; j++) {
		/* code */
		std::cout << this->product_sum(j) << '\n';
	}

	std::cout << "output" << '\n';
	for (size_t i = 0; i < 2; i++) {
		/* code */
		this->hidden_layer_outputs.push_back(
			this->sigmoid(
				this->product_sum(i) + this->bias[i]
			)
		);
		std::cout << this->sigmoid(this->product_sum(i) + this->bias[i]) << '\n';
	}

	std::cout << "hidden_layer_output" << '\n';
	for (size_t i = 0; i < this->hidden_layer_outputs.size(); i++) {
		/* code */
		std::cout << this->hidden_layer_outputs[i] << '\n';
	}

	std::cout << "hidden_product_sum" << '\n';
	std::cout << this->hidden_product_sum() << '\n';

	std::cout << "output_layer_bias" << '\n';
	std::cout << this->output_layer_bias << '\n';

	std::cout << "output layer output" << '\n';
	std::cout << this->sigmoid(
		this->hidden_product_sum() + this->output_layer_bias
	) << '\n';

	std::cout << "mean_squared_error" << '\n';
	std::cout << this->mean_squared_error() << '\n';
}

void input_node::set_target(double d){
	this->target = d;
}

double input_node::mean_squared_error(){
	return pow(
		(this->target-(
				this->sigmoid(
					this->hidden_product_sum() + this->output_layer_bias
					)
				)
			), 2.0
		);
}
double input_node::product_sum(int index){
	double product_sum;
	for (size_t j = 0; j < this->weights.size(); j++) {
		/* code */
		product_sum += this->weights[j][index] * this->inputs[j];
	}
	return product_sum;
}


double input_node::hidden_product_sum(){
	double product_sum;
	for (size_t j = 0; j < this->hidden_layer_weights.size(); j++) {
		/* code */
		product_sum += this->hidden_layer_weights[j] * this->hidden_layer_outputs[j];
	}
	return product_sum;
}
double input_node::sigmoid(double d){
	return 1/(1+exp(-d));
}
