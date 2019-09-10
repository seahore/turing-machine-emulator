q255: 初始化阶段，将加数的0和1分别换为a和b
q0: 加法结束，返回到最右位
q1-4: 检查加数第一至四位
q11-14: 发现第一至四位为正，越过加号后依位递减
q10: 被加数所在位取反；若为负转至q0，否则向左
q100: 加法完毕，停机

----------------

q255 B B L q255
q255 0 a L q255
q255 1 b L q255
q255 + + R q0

q0 0 0 R q0
q0 1 1 R q0
q0 + + R q0
q0 a a R q0
q0 b b R q0
q0 B B L q1

q1 a a L q2
q1 b a L q11
q2 a a L q3
q2 b a L q12
q3 a a L q4
q3 b a L q13
q4 a a L q100
q4 b a L q14

q11 a a L q11
q11 b b L q11
q11 + + L q10
q12 a a L q12
q12 b b L q12
q12 + + L q11
q13 a a L q13
q13 b b L q13
q13 + + L q12
q14 + + L q13

q10 0 1 R q0
q10 1 0 L q10

q11 0 0 L q10
q11 1 1 L q10
q12 0 0 L q11
q12 1 1 L q11
q13 0 0 L q12
q13 1 1 L q12

q100 + + N q100
