import java.util.*;

class SortedIntegerList {
	private LinkedList<Integer> data;
	boolean repeat;
	int first;
	SortedIntegerList(boolean n){
		repeat = n;
		data = new LinkedList<Integer>();
		first = 0;
	}

	final public void add(int n) {
		for(ListIterator<Integer> i = data.listIterator(); ; ) {
			if(!i.hasNext()) {
				data.add(n);
				break;
			}
			int cur = i.next();
			if(n <= cur) {
				if(!repeat) if(n == cur) break;
				i.previous();
				i.add(n);
				break;
			}
		}
	}

	final SortedIntegerList intersection(SortedIntegerList a) {
		SortedIntegerList temp = new SortedIntegerList(false);
		for(ListIterator<Integer> it = a.data.listIterator(); it.hasNext(); ) {
			int num = it.next();
			for(ListIterator<Integer> zit = this.data.listIterator(); zit.hasNext(); ) {
				if(num == zit.next()) temp.add(num);
			}
		}
		return temp;
	}

	final public void remove(int n) {
		for(ListIterator<Integer> i = data.listIterator(); i.hasNext(); ) {
			if(i.next() == n) {
				i.remove();
				while (i.hasNext() && i.next() == n) i.remove();
				break;
			}
		}
	}

	final public boolean equals(Object a) {
		if (a instanceof SortedIntegerList) {
			SortedIntegerList temp = (SortedIntegerList)a;
			ListIterator<Integer> i = this.data.listIterator();
			ListIterator<Integer> z = temp.data.listIterator();
			while(i.hasNext() && z.hasNext()) {
				if(i.next() != z.next()) return false;
			}
			if(i.hasNext() || z.hasNext()) return false;
			return true;
		}
		else {
			return false;
		}
	}

	final public String toString() {
		return data.toString();
	}
}
