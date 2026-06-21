# Write your MySQL query statement below
# select max(salary) as SecondHighestSalary from Employee where salary not in (select max(salary) from Employee);
select distinct(salary) as SecondHighestSalary from Employee union select null order by SecondHighestSalary desc limit 1,1;