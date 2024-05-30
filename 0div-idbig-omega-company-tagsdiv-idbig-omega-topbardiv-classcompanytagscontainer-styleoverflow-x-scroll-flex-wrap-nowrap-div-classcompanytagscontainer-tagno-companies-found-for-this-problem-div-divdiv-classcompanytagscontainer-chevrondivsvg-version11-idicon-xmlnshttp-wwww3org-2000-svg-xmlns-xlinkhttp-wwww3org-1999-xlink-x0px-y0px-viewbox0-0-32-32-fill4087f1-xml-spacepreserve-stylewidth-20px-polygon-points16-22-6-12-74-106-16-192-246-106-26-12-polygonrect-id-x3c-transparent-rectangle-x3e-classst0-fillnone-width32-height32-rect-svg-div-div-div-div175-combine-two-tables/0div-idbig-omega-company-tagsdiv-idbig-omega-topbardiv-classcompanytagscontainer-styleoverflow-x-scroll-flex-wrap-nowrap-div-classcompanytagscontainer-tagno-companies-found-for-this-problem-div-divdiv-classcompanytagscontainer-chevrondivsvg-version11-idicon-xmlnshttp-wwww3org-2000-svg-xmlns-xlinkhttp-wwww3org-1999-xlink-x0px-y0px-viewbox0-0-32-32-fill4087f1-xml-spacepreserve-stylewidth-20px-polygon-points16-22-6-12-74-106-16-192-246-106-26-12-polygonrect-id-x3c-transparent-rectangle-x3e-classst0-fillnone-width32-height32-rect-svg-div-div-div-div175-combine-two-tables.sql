# Write your MySQL query statement below

SELECT firstName, lastName, city, state from Person AS per LEFT JOIN Address AS ad ON per.personId = ad.personId; 