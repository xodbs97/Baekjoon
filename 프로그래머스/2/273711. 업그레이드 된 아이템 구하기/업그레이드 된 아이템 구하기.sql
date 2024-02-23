-- 코드를 작성해주세요
SELECT I.ITEM_ID,
I.ITEM_NAME,
I.RARITY
FROM ITEM_INFO I
JOIN ITEM_TREE T ON T.ITEM_ID = I.ITEM_ID
WHERE I.ITEM_ID = ANY (
    SELECT ITEM_ID
    FROM ITEM_TREE
    WHERE PARENT_ITEM_ID = ANY (
        SELECT ITEM_ID
        FROM ITEM_INFO
        WHERE RARITY = 'RARE'))
ORDER BY I.ITEM_ID DESC;