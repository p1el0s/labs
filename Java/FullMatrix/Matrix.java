public class Matrix{
	protected int[][] arr;
	protected int column;
	protected int row;
	
	public void setColumn(int n) {
		this.column = n;
	}

	public Matrix(int row, int column) throws MyException{
		if(row <= 0 || column <= 0) {
			throw new MyException("Error with constuctor");
		}
		this.column = column;
		this.row = row;
		arr = new int[row][column];
	}

	final public Matrix product(Matrix a) throws MyException{
		if(this.column != a.row) {
			throw new MyException("Row from matrix not similar column");
		}
		Matrix temp = new Matrix(a.row, a.column);
		for(int i = 0; i < row; i++)
			for(int z = 0; z < column; z++)
				for(int b = 0; b < column; b++)
					temp.setElement(i, z, temp.getElement(i, z) + this.getElement(i,b) * a.getElement(b,z));
					//temp.arr[i][z] += this.arr[i][b] * a.arr[b][z];
		return temp;
	}

	public Matrix(Matrix a) {
		this.arr = a.arr;
		this.column = a.column;
		this.row = a.row;
	}

	public Matrix sum(Matrix a) throws MyException{
		if(a.column != this.column || a.row != this.row) {
			throw new MyException("Matrix one not similar two.");
		}
		Matrix temp = new Matrix(a.row, a.column);
		for(int i = 0; i < row; i++)
			for(int z = 0; z < column; z++)
					temp.setElement(i, z, temp.getElement(i, z) + this.getElement(i,z) + a.getElement(i, z));
					//temp.arr[i][z] += this.arr[i][z] + a.arr[i][z];
		return temp;
	}

   public void setElement(int row, int column, int value) throws MyException{
		if(row < 0 || column < 0) {
			throw new MyException("Error with setElement");
		}
		arr[row][column] = value;
	}

   public int getElement(int row, int column) throws MyException{
		if(row < 0 || column < 0) {
			throw new MyException("Error with getElement");
		}
		return arr[row][column];
	}

	final public boolean equals(Matrix a){
        if(this == a) 
            return true;
        if(a.column != this.column || a.row != this.row) return false;
        for(int i = 0; i < row; i++)
           for(int j = 0; j < column; j++)
               	if(this.getElement(i,j) != a.getElement(i,j))
                    return false;
        return true;
    }

	public final String toString() {
		StringBuilder s = new StringBuilder();
		for (int i = 0; i < this.row; i++) {
			for(int z = 0; z < this.column; z++)
				s.append(this.getElement(i,z)).append(" ");
			s.append('\n');
		}
		return s.toString();
	}
}
