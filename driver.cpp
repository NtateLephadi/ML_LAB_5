#include "input_node.h"

int main(int argc, char const *argv[]) {
  /* code */
  input_node i;
  i.set_inputs({1.3, 2.7, 0.8});
  i.set_bias({0.1, -0.3});
  i.set_weights(
    {
      {0.1, -0.4},
      {0.2, 1.0},
      {0.5, -0.6}
    }
  );
  i.set_output_layer_bias(-0.3);
  i.set_hidden_layer_weights({0.8, 1});
  i.set_target(0.36);
  i.to_string();
  return 0;
}
