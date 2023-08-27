Sparse Matrix Multiplication

public int[][] multiply(int[][] A, int[][] B) {
  int[][] result = new int[A.length][B[0].length];
  ArrayList<ArrayList<Integer>> elements = new ArrayList<Integer>();
  for(int i = 0; i < A.length; i++) {
    ArrayList<Integer> nonzeroRowElements = new ArrayList<Integer>();
    for(int j = 0; j < A[i].length; j++) {
      if(A[i][j] != 0) {
        nonzeroRowElements.add(j);
      }
    }
  }

  for(int i = 0; i < elements.size(); i++) {
    ArrayList<Integer> indices = elements.get(i);
    for(int column = 0; column < B[0].length; column++) {
      for(int index: indices) {
        result[i][column] += A[i][index]*B[index][column];
      }
    }
  }
  return result;
}

public int[][] multiply2(int[][] A, int[][] B) {
  int[][] result = new int[A.length][B[0].length];
  for(int row = 0; row < A.length; row++) {
    for(int col = 0; col < A[row].length; col++) {
      if(A[row][col] != 0) {
        for(int j = 0; j < B[0].length; j++) {
          result[row][j] += A[row][col]*B[col][j];
        }
      }
    }
  }
  return result;
}

//Actually better off storing both nonzero elements in rows and columns
