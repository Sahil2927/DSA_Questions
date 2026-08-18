# Write your MySQL query statement below
-- select customer_id, count(customer_id) as count_no_trans
-- from Visits v
-- left join Transactions t
-- on v.visit_id = t.visit_id
-- where t.transaction_id is NULL
-- group by customer_id


-- 2nd approach
SELECT 
  customer_id, 
  COUNT(visit_id) AS count_no_trans 
FROM 
  Visits 
WHERE 
  visit_id NOT IN (
    SELECT 
      visit_id 
    FROM 
      Transactions
  ) 
GROUP BY 
  customer_id