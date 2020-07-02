for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                check[j] = false;
            }
            for(j=0;j<9;j++){
                if(!check[square[i][j]]){
                    check[square[i][j]] = true;
                }else{
                    return false;
                }
            }
        }