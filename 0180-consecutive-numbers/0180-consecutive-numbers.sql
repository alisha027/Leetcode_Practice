# Write your MySQL query statement below
SELECT DISTINCT l1.num AS ConsecutiveNums 
FROM Logs l1
JOIN Logs l2 On l1.id = l2.id - 1
JOIN Logs l3 On l1.id = l3.id - 2
WHERE l1.num = l2.num AND l2.num = l3.num;

