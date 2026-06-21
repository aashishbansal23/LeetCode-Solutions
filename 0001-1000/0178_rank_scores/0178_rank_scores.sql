# Write your MySQL query statement below
select score, (select count(*) from (select distinct score as s from scores) as tempTable where s>=score) as `rank` from scores order by score desc;