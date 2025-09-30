# Write your MySQL query statement below
SELECT id, COUNT(id) AS num
FROM (
    SELECT requester_id AS id
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id
    FROM RequestAccepted
) AS all_friends
GROUP BY id
HAVING COUNT(id) = (
    SELECT MAX(cnt)
    FROM (
        SELECT id, COUNT(id) AS cnt
        FROM (
            SELECT requester_id AS id
            FROM RequestAccepted
            UNION ALL
            SELECT accepter_id AS id
            FROM RequestAccepted
        ) AS t
        GROUP BY id
    ) AS sub
);
