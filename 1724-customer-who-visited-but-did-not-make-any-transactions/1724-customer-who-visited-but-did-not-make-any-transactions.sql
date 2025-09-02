select customer_id, count(*) as count_no_trans
from (
select v.customer_id, t.transaction_id
from Visits v left join Transactions t
on v.visit_id = t.visit_id ) as temp
where transaction_id is null
group by customer_id;




