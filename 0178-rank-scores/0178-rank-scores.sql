SELECT s1.score,
       COUNT(DISTINCT s2.score) + 1 AS `rank`
FROM Scores s1
LEFT JOIN Scores s2
  ON s2.score > s1.score
GROUP BY s1.id, s1.score
ORDER BY s1.score DESC;


