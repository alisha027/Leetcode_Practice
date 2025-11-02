# Write your MySQL query statement below
SELECT customer_id
FROM (SELECT customer_id,SUM(CASE WHEN transaction_type = 'purchase' THEN 1 ELSE 0 END) AS purchase_count,
        SUM(CASE WHEN transaction_type = 'refund' THEN 1 ELSE 0 END) AS refund_count,
        COUNT(*) AS total_transactions,
        DATEDIFF(MAX(transaction_date), MIN(transaction_date)) AS active_days
    FROM customer_transactions GROUP BY customer_id
) AS stats WHERE purchase_count >= 3 AND active_days >= 30 AND refund_count / total_transactions < 0.2
ORDER BY customer_id;
