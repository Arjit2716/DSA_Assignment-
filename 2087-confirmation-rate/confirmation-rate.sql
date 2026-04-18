# Write your MySQL query statement below
select s.user_id,  ROUND(COALESCE(AVG(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END), 0), 2) AS confirmation_rate from Signups s  LEFT JOIN Confirmations c
on s.user_id=c.user_id
group by s.user_id; 
 