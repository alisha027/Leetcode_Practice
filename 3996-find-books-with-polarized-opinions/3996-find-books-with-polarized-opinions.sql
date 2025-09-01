# Write your MySQL query statement below
SELECT b.book_id,b.title,b.author,b.genre,b.pages,
    MAX(r.session_rating) - MIN(r.session_rating) AS rating_spread,
    ROUND(
        SUM(CASE WHEN r.session_rating <= 2 OR r.session_rating >= 4 THEN 1 ELSE 0 END) / COUNT(*),
        2
    ) AS polarization_score
FROM books b
JOIN reading_sessions r 
ON b.book_id = r.book_id
GROUP BY b.book_id, b.title, b.author, b.genre, b.pages
HAVING 
    COUNT(*) >= 5  -- at least 5 sessions
    AND MAX(r.session_rating) >= 4  -- has high rating
    AND MIN(r.session_rating) <= 2  -- has low rating
    AND (SUM(CASE WHEN r.session_rating <= 2 OR r.session_rating >= 4 THEN 1 ELSE 0 END) / COUNT(*)) >= 0.6
ORDER BY 
    polarization_score DESC,
    b.title DESC;
