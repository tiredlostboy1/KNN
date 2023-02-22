#ifndef KNN_H
#define KNN_H
#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

class KNN {
private:
  std::vector<std::vector<float>> x_train;
  std::vector<int> y_train;
  int k;

  float distance(const std::vector<float> &a, const std::vector<float> &b) {
    float d = 0;
    for (int i = 0; i < a.size(); ++i) {
      d += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(d);
  }

public:
  KNN(int k) : k(k) {}

  void fit(const std::vector<std::vector<float>> &x_train,
           const std::vector<int> &y_train) {
    this->x_train = x_train;
    this->y_train = y_train;
  }

  std::vector<int> predict(const std::vector<std::vector<float>> &x_test) {
    std::vector<int> result{};
    for (auto &sample : x_test) {
      std::vector<std::pair<float, int>> distances;
      for (int i = 0; i < x_train.size(); ++i) {
        // for(auto& train_sample : x_train){
        distances.push_back({distance(sample, x_train[i]), y_train[i]});
      }
      std::sort(distances.begin(), distances.end());
      std::map<int, int> frequencies{};
      for (int i = 0; i < k; ++i) {
        int label = distances[i].second;
        frequencies[label]++;
      }
      for (auto& [a, b] : frequencies) {
        std::cout << a << ' ' << b << std::endl;
      }
      std::map<int, int> freqs;
      for (auto&[key, value]: frequencies) {
        freqs.insert({value, key});
      }
      result.push_back(freqs.rbegin()->second);
    }
    return result;
  }
};

#endif