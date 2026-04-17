# Write your MySQL query statement below
select e.name from Employee e join Employee o
where e.id=o.managerId
group by e.id,e.name having count(e.id)>=5
;