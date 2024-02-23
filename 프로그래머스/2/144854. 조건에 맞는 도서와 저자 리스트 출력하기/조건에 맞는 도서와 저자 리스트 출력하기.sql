SELECT BOOK_ID,
AUTHOR_NAME,
DATE_FORMAT(PUBLISHED_DATE, "%Y-%m-%d") AS PUBLISHED_DATE
FROM AUTHOR AS A
LEFT JOIN BOOK AS B ON B.AUTHOR_ID = A.AUTHOR_ID
WHERE CATEGORY = '경제'
ORDER BY PUBLISHED_DATE ASC;