# Write your MySQL query statement below
select distinct c.customer_id from customer c
join product p
on c.product_key = p.product_key
group by c.customer_id
having count(distinct c.product_key) = (SELECT COUNT(*) FROM Product);
