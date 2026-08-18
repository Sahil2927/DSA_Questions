# Write your MySQL query statement below
select p.product_id, round(ifnull(sum(units*price)/sum(units),0),2) as average_price
from Prices p
left join UnitsSold u
on p.product_id=u.product_id
and purchase_date between start_date and end_date
group by product_id