# Write your MySQL query statement below

-- select round(avg(order_date=customer_pref_delivery_date)*100,2) as immediate_percentage
-- from Delivery
-- where (customer_id,order_date)in(
--     select customer_id, min(order_date)
--     from Delivery
--     group by customer_id
-- )


-- Approach 2

WITH RankedOrders AS (
    SELECT 
        customer_id,
        order_date,
        customer_pref_delivery_date,
        ROW_NUMBER() OVER(PARTITION BY customer_id ORDER BY order_date) as rn
    FROM Delivery
)
SELECT 
    ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
FROM RankedOrders
WHERE rn = 1;
