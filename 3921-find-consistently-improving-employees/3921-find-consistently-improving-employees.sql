WITH ranked_reviews AS (
    SELECT 
        employee_id,
        rating,
        review_date,
        ROW_NUMBER() OVER (PARTITION BY employee_id ORDER BY review_date DESC) AS rn
    FROM performance_reviews
),
last_three AS (
    SELECT 
        employee_id,
        rating,
        rn
    FROM ranked_reviews
    WHERE rn <= 3
),
check_improvement AS (
    SELECT 
        employee_id,
        MIN(CASE WHEN rn = 1 THEN rating END) AS r1,
        MIN(CASE WHEN rn = 2 THEN rating END) AS r2,
        MIN(CASE WHEN rn = 3 THEN rating END) AS r3
    FROM last_three
    GROUP BY employee_id
)
SELECT 
    e.employee_id,
    e.name,
    (c.r1 - c.r3) AS improvement_score
FROM check_improvement c
JOIN employees e ON c.employee_id = e.employee_id
WHERE c.r3 < c.r2 AND c.r2 < c.r1   
ORDER BY improvement_score DESC, name ASC;