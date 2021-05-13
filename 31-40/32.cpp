void convertToLogs(vector<vector<double> > &exchange){
    int n = exchange.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            exchange[i][j] = -(log10(exchange[i][j]));
        }
    }
    return ;
}


bool isPossibleArbitrage(vector<vector<double> > &exchange, int src){
    int n = exchange.size();

    vector<double> dist(n, INT_MAX);

    convertToLog(exchanges);

    dist[src] = 0;

    for(int i=0; i<n-1; i++){
        bool flag = false;

        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){
                if(exchange[i][j]){
                    if(dist[j] != INT_MAX && dist[j] < dist[i] + exchange[i][j]){

                        dist[j] = dist[i] + exchange[i][j];
                        flag = true;

                    }
                }
            }
        }
        if(!flag){
            return false;
        }
    }

    flag = false;

    for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){
                if(exchange[i][j]){
                    if(dist[j] != INT_MAX && dist[j] < dist[i] + exchange[i][j]){

                        dist[j] = dist[i] + exchange[i][j];
                        flag = true;

                    }
                }
                if(flag){
                    return true;
                }
            }
    }

        return flag;
}