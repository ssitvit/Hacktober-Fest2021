# K-Means Algorithm
> The objective of K-means is to group similar data points together and discover underlying patterns. To achieve this objective, K-means looks for a fixed number (k) of clusters in a dataset.

> To read more about the algorithm, read [this](https://towardsdatascience.com/understanding-k-means-clustering-in-machine-learning-6a6e67336aa1)

### Input
- The x coordinates of the points in the dataset
- The y-coordinates of the points in the dataset
- Number of clusters to be formed
- The k points, for eg. 1st & 5th point

### Output
- Step by step calculation of the k cluster points

### Sample Input
```
1.0 1.5 3.0 5.0 3.5 4.5 3.5
1.0 2.0 4.0 7.0 5.0 5.0 4.5
```
Enter number of clusters`2`

Enter initial centroids`1 4`

  - The first line contains the x coordinates of the points, n space separated float values
  - The second line contains the y coordinates of the points, n space separated float values
  - Third input is the number of clusters, an integer, k
  - Fourth input is k space separated integers, each denoting the point position (1-based indexing)

### Final Output
```
Final Clusters are
Cluster 1 = 
[1, 2]
Cluster 2 = 
[3, 4, 5, 6, 7]
```

> The above output is the final solution to the problem. However, the complete output (including steps) can be found [here](https://github.com/Shreya549/Hacktober-Fest2021/blob/main/Machine-Learning/K-Means%20Clustering/output.txt)

#### This is very useful for college students undertaking courses like Machine Learning, Big Data Analytics, Data Mining, Artificial Intelligence and other similar courses as numericals on K-means is often a part of the curriculum. Using this, one can get the step-wise solution to their complex numerical within a second, which otherwise takes 15-20 mins to solve manually. 

