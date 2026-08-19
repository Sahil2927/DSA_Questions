# Write your MySQL query statement below
select e2.employee_id,e2.name,count(e.employee_id) as reports_count,round(avg(e.age))as average_age
from Employees e
join Employees e2
on e.reports_to=e2.employee_id
group by e.reports_to
order by employee_id;