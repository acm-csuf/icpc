//---------------------inputs-------------------------
// int type : n.  
//		- the number of nodes
// array of double type: cMat. 
//		- connectivity matrix, 0 means disconnected 
//		  and distances are all positive.  
//		- Is of length (n*n).
//---------------------outputs-------------------------
//double** type: dist_mat
//		- the shortest path, (ANSWER)
//int** type: pred_mat
//		- predicate matrix, used for reconstructing 
//		  shortest routes

void warshall(int n, double *cmat, double **dist_mat, int **pred_mat){
	double *dist;
	int *pred;
	int i, j, k; //counters

	//initialize data structs
	dist = (double *)malloc(sizeof(double) * n * n);//allocate dist[n*n]
	pred = (int *)malloc(sizeof(int) * n * n);//allocate pred[n*n]
	memset(dist, 0, sizeof(double)*n*n);//sets dist[all indices] to 0
	memset(pred, 0, sizeof(int)*n*n);//sets pred[all indices] to 0

	//initialize algorithm
	for ( i = 0; i < n; i++ ){
		for ( j= 0; j < n; j++ ){
			if (cmat[i*n+j] != 0.0)
				dist[i*n+j] = cmat[i*n + j];
			else
				dist[i*n+j] = HUGE_VAL; //path disconnected

			if (i == j) //diagonal case
				dist[i*n+j] = 0;

			if ((dist[i*n +j] > 0.0) && (dist[i*n+j] < HUGE_VAL))
				pred[i*n+j] = i;
		}
	}

	//main loop
	for ( k = 0; k < n; k ++ ) {
		for ( i = 0; i < n; i ++ ) {
			for ( j = 0; j < n; j ++ ) {
				if ( dist[i*n+j] > (dist[i*n+k] + dist[k*n+j])) {
					dist[i*n+j] = dist[i*n+k] + dist[k*n+j];
					pred[i*n+j] = k;
				}
			}
		}
	}

	//print out results of all the shortest dist
	//***if we want to output right away***
	/*
	for( i = 0; i < n; i++) {
		for ( j = 0; j < n; j++) {
			cout << dist[i*n+j] << endl;
		}
	}
	*/

	if ( dist_mat )
		*dist_mat = dist;
	else
		free(dist);

	if ( pred_mat )
		*pred_mat = pred;
	else
		free(pred);
}