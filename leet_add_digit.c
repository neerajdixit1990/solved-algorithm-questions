#include<stdio.h>
int addDigits(int num) {
	int	ans;
	while(1) {
		ans = 0;
		while(num != 0) {
			ans = ans + num%10;
			num = num/10;
		}
		
		if (ans/10 == 0)
			return ans;
		else
			num = ans;
	}
}

int main() {
	int	ans;
	ans = addDigits(3749);
	printf("\nSingle digit answer is %d\n", ans);
	return 0;
}
