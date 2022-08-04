# Write your MySQL query statement below
select max(salary) as SecondHighestSalary from Employee where salary not in (select max(salary) from Employee);
# select salary as SecondHighestSalary from Employee group by salary order by salary desc limit 1,1;