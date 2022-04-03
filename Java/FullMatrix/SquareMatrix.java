public class SquareMatrix extends Matrix{
	private int size;

	public SquareMatrix(int size) {
		super(size,size);
		this.size = size;
		for(int i = 0; i < size; i++)
			for(int z = 0; z < size; z++)
				if(i == z) this.setElement(i,i,1);
	}

	final public SquareMatrix sum(SquareMatrix a) throws MyException{
		if(this.size != a.size) {
			throw new MyException("Matrix one not similar two.");
		}
		SquareMatrix temp = new SquareMatrix(a.size);
		temp.clearMatrix();
		for(int i = 0; i < size; i++) {
			for(int z = 0; z < size; z++) {
				int val = temp.getElement(i, z);
				val += this.getElement(i, z) + a.getElement(i, z);
				temp.setElement(i, z, val);
			}
		}
		return temp;
	}

	final public void clearMatrix() {
		for(int i = 0; i < size; i++)
			for(int b = 0; b < size; b++)
				this.setElement(i,b,0);
	}
}
