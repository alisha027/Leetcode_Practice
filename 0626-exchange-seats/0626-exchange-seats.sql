# Write your MySQL query statement below
SELECT
    id, 
    CASE
        WHEN id % 2 = 1 AND id = (SELECT MAX(id) FROM Seat) THEN student
        WHEN id % 2 = 1 THEN LEAD(student, 1) OVER (ORDER BY id)
        WHEN id % 2 = 0 THEN LAG(student, 1) OVER (ORDER BY id) 
        ELSE student 
    END AS student 
FROM
    Seat
ORDER BY
    id;