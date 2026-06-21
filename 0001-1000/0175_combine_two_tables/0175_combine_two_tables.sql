# Write your MySQL query statement below
select p.firstName, p.lastname, a.city, a.state from person as p LEFT JOIN address as a on p.personId = a.personId;