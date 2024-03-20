
concepts covered
- linear list
- tree 
- graph

### the application of arrays

> used to solve two fundamental problems in representing and storing high precision numbers

```c
int a[100] = {0}
int n
string s
cin >> s
n = s.length();
for(i=0 ; i<n; i++)
```

rules for addition and subtraction are similar to those in normal rules of arithmetic addition and subtraction

```c
for (i=0; i<(n1<n2 ? n1 : n2); i++){
	a[i] = a[i] + b[i]; // bitwise addition
	
	if( a[i] > 9) { // we carry over the number to the leftside number
		a[i] = a[i] - 10;
		a[i + 1]++
	}
}
```

#### Subtraction of high precision numbers
when we are doing subtraction, we'll need to implement borrow over from the next number in the array

```c
for (i=0: i<n; i++){
	if(a[i] >= b[i])
		a[i] = a[i] - b[i]
	else {
		a[i] = a[i] + 10 - b[i];
		a[i+1]--
	}
}
```

#### Multiplication of high precision numbers

> Lower limit for the number of digits in the product: LA + LB - 1
> Upper limit: LA + LB

where LA is the number of digits for a and LB is the number of digits for b

```c
for (i=0; i< -LA - 1; i++)
// product of each digit of multiplicand a and multiplier b is accumulated to corresponding digits or array c
	for(j=1 ; j < -LB - 1; j++)
		if(c[i] >= 10){
			c[i+1] += c[10] / 10
			c[i] %= 10
		}
```

IDs for Online Judge: POJ 1504, ZOJ 2001, UVA 713

## Huffman Trees 

> For n leaves, there are 2n - 1 nodes

## Breadth-First Search 

![[Pasted image 20231202100839.png]]
