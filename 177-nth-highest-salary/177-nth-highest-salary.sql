CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct(salary) as getNthHighestSalary from employee union select null order by getNthHighestSalary desc limit N, 1
  );
END