 /**
 * @file solution.h
 * @author tianqingshuai(tqingshuai@gmail.com)
 * @date 2018/06/08 16:40:55
 * @brief
 *
 **/

#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t lenf = word1.length();
        size_t lens = word2.length();

        if (lenf == 0 || lens == 0) {
            return lenf + lens;
        }

        vector<vector<int>> dist;
		dist.reserve(lenf);
		for (size_t i = 0; i < lenf; ++i) {
			vector<int>  tdist (lens, 0);
			dist[i] = tdist;
		}

        for (size_t i = 0; i < lenf; ++i) {
            for (size_t j = 0; j < lens; ++j) {
                if (i == 0) {
                    if (word1[i] == word2[j]) {
						dist[i][j] = j;
                    } else {
                        dist[i][j] = j > 0 ? dist[i][j - 1] + 1 : 1;
                    }
                    continue;
                }
                if (j == 0) {
                    if (word1[i] == word2[j]) {
						dist[i][j] = j;
                    } else {
						dist[i][j] = i > 0 ? dist[i-1][j] + 1 : 1;
                    }
                    continue;
                }
                if (word1[i] == word2[j]) {
					dist[i][j] = dist[i-1][j-1];
                } else {
					dist[i][j] = 1 + min(dist[i-1][j-1], dist[i][j-1], dist[i-1][j]);
                }
            }
        }

        return dist[lenf - 1][lens - 1];
    }

    int min(int a, int b, int c) {
        int minv = a < b ? a : b;
        minv = minv < c ? minv : c;
        return minv;
    }
};

#endif  //_SOLUTION_H

/* vim: set ts=4 sw=4 sts=4 tw=100 */
