# Write your MySQL query statement below
DELETE e1 
FROM Person e1
JOIN Person e2
ON e1.email = e2.email WHERE e1.id > e2.id;
