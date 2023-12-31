## General Problem Solving Tips
문제 분할을 어떻게 하느냐에 따라 구현의 난이도가 크게 달라진다.
잘 안 풀리면, 일단 내가 컴퓨터가 되어서 그 문제를 풀어보자.

## Dynamic Programming tips
일단 웬만하면 f(n)과 f(n-1), f(n-2) 등과의 관계로 표현하려고 하자.
그게 안되면 f(n)을 몇가지 case로 나눌 수 있다.
그것도 안되면 f(n) 자체가 아니라 n번째는 무조건 포함하는 g(n)을 기준으로 DP를 실행할 수 있다.