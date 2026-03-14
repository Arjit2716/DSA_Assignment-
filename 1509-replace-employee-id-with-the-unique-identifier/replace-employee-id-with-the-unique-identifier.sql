# Write your MySQL query statement below
-- select EmployeeUNI.unique_id, Employees.name from Employees
-- Left join EmployeeUNI on Employees.id=EmployeeUNI.unique_id;

select euni.unique_id,e.name from Employees e
left join EmployeeUNI euni on e.id=euni.id;