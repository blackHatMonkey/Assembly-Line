// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 23/10/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

namespace w7 {

/**
 * Represents a class that holds x and y coordinates for a graph.
 *
 */
template <typename T>
class DataTable {
   public:
    DataTable(std::ifstream& file, int fieldWidth, int precisionWidth);
    auto mean() const -> T;
    auto sigma() const -> T;
    auto median() const -> T;
    auto regression(T& slope, T& y_intercept) const -> void;
    auto display(std::ostream& out) const -> void;
    auto getSize() const -> size_t;

   private:
    int precision;
    int width;
    std::vector<std::pair<T, T>> data;
};

/**
 * Read the file expecting the following format:
 * x1 y1
 * x2 y2
 *
 */
template <typename T>
DataTable<T>::DataTable(std::ifstream& file, int fieldWidth,
                        int precisionWidth) {
    precision = precisionWidth;
    width = fieldWidth;

    T x;
    T y;
    while (file >> x >> y) {
        data.push_back(std::pair<T, T>(x, y));
    }
}

/**
 * Calculate the mean of the data using:
 * ∑yᵢ ⁄ n
 *
 */
template <typename T>
auto DataTable<T>::mean() const -> T {
    return std::accumulate(data.begin(), data.end(), (T)0,
                           [](T a, const std::pair<T, T>& b) -> T {
                               return a + b.second;
                           }) /
           data.size();
}

/**
 * Calculate the standard deviation of data using:
 * √(yᵢ - y mean)² / n - 1
 *
 */
template <typename T>
auto DataTable<T>::sigma() const -> T {
    T meanVal = mean();
    return std::sqrt(std::accumulate(data.begin(), data.end(), T(0),
                                     [&](T a, const std::pair<T, T>& b) {
                                         return a +
                                                std::pow(b.second - meanVal, 2);
                                     }) /
                     (data.size() - 1));
}

/**
 * @brief Calculate the median of the data.
 *
 * @tparam T any type.
 * @return T median of the data.
 */
template <typename T>
auto DataTable<T>::median() const -> T {
    std::vector<T> copy;

    for (auto i : data) {
        copy.push_back(i.second);
    }

    std::sort(copy.begin(), copy.end());

    return copy[copy.size() / 2];
}

/**
 * @brief Calculate the slope and y intercept of data.
 *
 * @tparam T any type.
 * @param slope slope of the graph.
 * @param y_intercept y intercept of graph.
 */
template <typename T>
auto DataTable<T>::regression(T& slope, T& y_intercept) const -> void {
    auto size = data.size();

    // ∑(xᵢ)
    auto sumX = std::accumulate(
        data.begin(), data.end(), (T)0,
        [](T a, const std::pair<T, T>& b) { return a + b.first; });
    // ∑(yᵢ)
    auto sumY = std::accumulate(
        data.begin(), data.end(), (T)0,
        [](T a, const std::pair<T, T>& b) { return a + b.second; });

    // ∑(xᵢ yᵢ)
    auto sumXY = std::accumulate(
        data.begin(), data.end(), (T)0,
        [](T a, const std::pair<T, T>& b) { return a + (b.first * b.second); });

    // ∑(xᵢ²)
    auto sumX2 = std::accumulate(
        data.begin(), data.end(), (T)0,
        [](T a, const std::pair<T, T>& b) { return a + std::pow(b.first, 2); });

    // n(∑(xᵢ yᵢ)) - ∑(xᵢ) // ∑(yᵢ) / n(∑(xᵢ²)) - ∑(xᵢ)²
    slope = ((size * (sumXY)) - (sumX * sumY)) /
            ((size * sumX2) - std::pow(sumX, 2));

    // ∑(yᵢ) - (slope * ∑(xᵢ))/ n
    y_intercept = (sumY - (slope * sumX)) / size;
}

/**
 * @brief Display the data
 *
 * @tparam T any type.
 * @param out output stream.
 */
template <typename T>
auto DataTable<T>::display(std::ostream& out) const -> void {
    for (auto i : data) {
        out << std::fixed << std::setw(width) << std::setprecision(precision)
            << i.first << std::setw(width) << i.second << std::endl;
    }
}

/**
 * @brief Return the size of collection.
 *
 * @tparam T any type.
 * @return size_t number of x, y coordinates.
 */
template <typename T>
auto DataTable<T>::getSize() const -> size_t {
    return data.size();
}

/**
 * @brief Display data in DataTable object.
 *
 * @tparam T any type.
 * @param out output stream.
 * @param data object holding x, y coordinates.
 * @return std::ostream&  output stream.
 */
template <typename T>
auto operator<<(std::ostream& out, const DataTable<T>& data) -> std::ostream& {
    data.display(out);
    return out;
}

}  // namespace w7

#endif