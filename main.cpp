#include "KNN.hpp"

int main() {
  std::vector<std::vector<float>> x_train{{0, 0}, {1, 1}, {2, 2}, {-1, 0}};
  std::vector<int> y_train{1, 2, 3, 1};
  std::vector<std::vector<float>> x_test{{0.2, 1}, {1, 3}};
  KNN clf(1);
  clf.fit(x_train, y_train);
  auto y_pred = clf.predict(x_test);
  std::cout << y_pred[0];
}
