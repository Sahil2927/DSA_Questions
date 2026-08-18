# Write your MySQL query statement below
with first_login as(
    select player_id,min(event_date) as firstLogin
    from Activity
    group by player_id
),
next_login as(
    select a.player_id
    from Activity a
    join first_login f
    on a.player_id=f.player_id
    and datediff(a.event_date,f.firstLogin)=1
)
select round(count(n.player_id)*1.0/count(f.player_id),2) as fraction
from first_login f
left join next_login n
on f.player_id=n.player_id;



-- with firstLogin as(
--     select player_id, min(event_date) as firstlogin
--     from Activity
--     group by player_id
-- ),
-- nextDayLogin as(
--     select distinct(a.player_id)
--     from Activity a
--     join firstLogin f
--     on a.player_id=f.player_id
--     and datediff(a.event_date,f.firstlogin)=1
-- )
-- select round(
--     count(n.player_id)*1.0/count(f.player_id),2
--     ) as fraction
-- from firstLogin f
-- left join nextDayLogin n
-- on f.player_id=n.player_id;