# Write your MySQL query statement below
-- select a1.machine_id,round(avg(a2.timestamp-a1.timestamp),3) as processing_time
-- from Activity a1
-- join Activity a2
-- on a1.machine_id = a2.machine_id and a1.process_id = a2.process_id and a1.activity_type='start' and a2.activity_type='end'
-- group by a1.machine_id;


-- Approach 2
WITH ProcessWeights AS (
    SELECT 
        machine_id,
        process_id,
        CASE 
            WHEN activity_type = 'start' THEN -timestamp 
            ELSE timestamp 
        END AS adjusted_timestamp
    FROM Activity
)
SELECT 
    machine_id,
    ROUND(SUM(adjusted_timestamp) / COUNT(DISTINCT process_id), 3) AS processing_time
FROM ProcessWeights
GROUP BY machine_id;